use lib "t/lib";
use TestAuto;

use strict;
use warnings;

use Test::More;

use SPVM 'TestCase::Lib::Webkit::CookieJar::CookieParser';

# Start objects count
my $start_memory_blocks_count = SPVM::get_memory_blocks_count();

# SPVM::Webkit::CookieJar::CookieParser
{
  ok(SPVM::TestCase::Lib::Webkit::CookieJar::CookieParser->test_parse_only_key_value);
  # TODO: Implement 'locale' in strptime.
  #ok(SPVM::TestCase::Lib::Webkit::CookieJar::CookieParser->test_parse_expires);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar::CookieParser->test_parse_max_age);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar::CookieParser->test_parse_domain);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar::CookieParser->test_parse_path);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar::CookieParser->test_parse_secure);
  ok(SPVM::TestCase::Lib::Webkit::CookieJar::CookieParser->test_parse_http_only);
}

# All object is freed
my $end_memory_blocks_count = SPVM::get_memory_blocks_count();
is($end_memory_blocks_count, $start_memory_blocks_count);

done_testing;
