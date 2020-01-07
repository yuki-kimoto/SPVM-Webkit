#include "spvm_native.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <signal.h>

#ifdef _WIN32
# include <ws2tcpip.h>
# include <io.h>
#else
# include <sys/fcntl.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <unistd.h>
# define closesocket(fd) close(fd)
#endif

// Module file name
static const char* MFILE = "SPVM/HTTP/Client/Socket.c";

int32_t SPNATIVE__SPVM__Webkit__Socket__new(SPVM_ENV* env, SPVM_VALUE* stack) {

#ifdef _WIN32
  // Load WinSock DLL
  WSADATA wsa;
  WSAStartup(MAKEWORD(2, 2), &wsa);
#else
  // Ignore SIGPIPE in unix like system
  signal(SIGPIPE, SIG_IGN);
#endif

  // Dest string. Domain or IP address
  void* obj_deststr = stack[0].oval;
  const char* deststr = (const char*)env->get_elems_byte(env, obj_deststr);
  
  // Port
  int32_t port = stack[1].ival;
  
  // Socket handle
  int32_t handle = socket(AF_INET, SOCK_STREAM, 0);
  if (handle < 0) {
    SPVM_DIE("Can't create socket", MFILE, __LINE__);
  }
  
  // Socket information
  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(deststr);
  server.sin_port = htons(port);
  
  // Get IP address from domain
  if (server.sin_addr.s_addr == 0xffffffff) {
    // Find host
    struct hostent *host;
    host = gethostbyname(deststr);
    if (host == NULL) {
      SPVM_DIE("host not found : %s", deststr, MFILE, __LINE__);
    }
    
    // No IP address
    unsigned int **addrptr = (unsigned int **)host->h_addr_list;
    if (*addrptr == NULL) {
      SPVM_DIE("Can't get ip address from host information : %s", deststr, MFILE, __LINE__);
    }
    server.sin_addr.s_addr = *(*addrptr);
  }
  
  // Connect
  int32_t ret = connect(handle, (struct sockaddr *)&server, sizeof(server));
  if (ret != 0) {
    SPVM_DIE("Can't connect to HTTP server : %s:%d", deststr, port, MFILE, __LINE__);
  }
  
  // Create SPVM::Webkit::Socket object
  void* obj_socket;
  SPVM_NEW_OBJECT(env, obj_socket, "SPVM::Webkit::Socket", MFILE, __LINE__);
  
  // Set handle
  SPVM_SET_FIELD_INT(env, obj_socket, "SPVM::Webkit::Socket", "handle", handle, MFILE, __LINE__);
  
  stack[0].oval = obj_socket;
  
  return SPVM_SUCCESS;
}

int32_t SPNATIVE__SPVM__Webkit__Socket__read(SPVM_ENV* env, SPVM_VALUE* stack) {
  void* obj_socket = stack[0].oval;
  void* obj_buffer = stack[1].oval;
  const char* buffer = (const char*)env->get_elems_byte(env, obj_buffer);
  int32_t length = env->length(env, obj_buffer);
  
  int32_t handle;
  SPVM_GET_FIELD_INT(env, handle, obj_socket, "SPVM::Webkit::Socket", "handle", MFILE, __LINE__);

  if (handle < 0) {
    SPVM_DIE("Handle is closed", MFILE, __LINE__);
  }
  
  /* HTTP���N�G�X�g���M */
  int32_t read_length = recv(handle, (char*)buffer, length, 0);
  if (read_length < 0) {
    SPVM_DIE("Socket read error", MFILE, __LINE__);
  }
  
  stack[0].ival = read_length;
  
  return SPVM_SUCCESS;
}

int32_t SPNATIVE__SPVM__Webkit__Socket__write(SPVM_ENV* env, SPVM_VALUE* stack) {
  void* obj_socket = stack[0].oval;
  void* obj_buffer = stack[1].oval;
  const char* buffer = (const char*)env->get_elems_byte(env, obj_buffer);
  int32_t length = stack[2].ival;
  
  int32_t handle;
  SPVM_GET_FIELD_INT(env, handle, obj_socket, "SPVM::Webkit::Socket", "handle", MFILE, __LINE__);
  
  if (handle < 0) {
    SPVM_DIE("Handle is closed", MFILE, __LINE__);
  }
  
  /* HTTP���N�G�X�g���M */
  int32_t write_length = send(handle, buffer, length, 0);
  
  if (write_length < 0) {
    SPVM_DIE("Socket write error", MFILE, __LINE__);
  }
  
  stack[0].ival = write_length;
  
  return SPVM_SUCCESS;
}

int32_t SPNATIVE__SPVM__Webkit__Socket__close(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  void* obj_socket = stack[0].oval;
  
  int32_t handle;
  SPVM_GET_FIELD_INT(env, handle, obj_socket, "SPVM::Webkit::Socket", "handle", MFILE, __LINE__);
  
  if (handle >= 0) {
    int32_t ret = closesocket(handle);
    if (ret == 0) {
      SPVM_SET_FIELD_INT(env, obj_socket, "SPVM::Webkit::Socket", "handle", -1, MFILE, __LINE__);
    }
    else {
      SPVM_DIE("Fail close", MFILE, __LINE__);
    }
  }
  
  return SPVM_SUCCESS;
}

int32_t SPNATIVE__SPVM__Webkit__Socket__fileno(SPVM_ENV* env, SPVM_VALUE* stack) {
  // Self
  void* obj_self = stack[0].oval;
  if (!obj_self) { SPVM_DIE("Self must be defined", MFILE, __LINE__); }
  
  // File fh
  int32_t handle;
  SPVM_GET_FIELD_INT(env, handle, obj_self, "SPVM::Webkit::Socket", "handle", MFILE, __LINE__);
  
  stack[0].ival = handle;

  return SPVM_SUCCESS;
}

int32_t SPNATIVE__SPVM__Webkit__Socket___cleanup_wsa(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  // Unload WinSock DLL
#ifdef _WIN32
  WSACleanup();
#endif
  
  return SPVM_SUCCESS;
}
