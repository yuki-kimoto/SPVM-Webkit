package Webkit::MIME::Base64;

use SPVM 'Webkit::MIME::Base64';

1;

=head1 NAME

Webkit::MIME::Base64 - Base64 encode/decode

=head1 SYNOPSYS
  
  use Webkit::MIME::Base64;
  
  my $b64 = Webkit::MIME::Base64->new;
  my $text = $b64->encode($binary);
  my $binary = $b64->decode($text);

=head1 DESCRIPTION

Base64 encode/decode

=head1 METHODS

=head2 new

  static method new : Webkit::MIME::Base64 ()

Create new L<Webkit::MIME::Base64> object.

=head2 encode

  method encode : string ($binary : string)

Encode binary data to base64 text.

=head2 decode

  method decode : string ($base64_text : string)

Decode encoded Base64 text to binary data.
