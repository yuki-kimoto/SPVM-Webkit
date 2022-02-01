use lib "t/lib";
use TestAuto;

use strict;
use warnings;

use Test::More;

use SPVM 'TestCase::Lib::Webkit::CookieJar';

# Start objects count
my $start_memory_blocks_count = SPVM::get_memory_blocks_count();

# SPVM::Webkit::CookieJar
{
  ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_add_key_value);
  # TODO: Implement 'locale' in strptime to comment-out.
  #ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_add_expires);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_add_max_age);
  # TODO: Implement 'locale' in strptime to comment-out.
  #ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_add_prioritize_max_age_over_expires);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_add_expires_infinity);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_add_domain);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_add_domain_use_host_only_when_no_domain);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_add_domain_use_host_only_when_no_domain_request_root_path);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_add_domain_not_host_only_even_if_same_as_request_domain);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_add_domain_ignore_cookie_when_different_domain);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_add_path_last_is_dir_when_no_path_attr);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_add_path_last_is_file_when_no_path_attr);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_add_path_use_default_path_when_broken_root);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_add_path_prioritize_path_attr_over_request_path);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_add_secure);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_add_http_only);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_add_update_cookie);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_cookies_for);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_cookies_for_returning_value_order);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar->test_cookie_header);
}

# All object is freed
my $end_memory_blocks_count = SPVM::get_memory_blocks_count();
is($end_memory_blocks_count, $start_memory_blocks_count);

done_testing;
