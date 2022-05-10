use strict;
use warnings;
use FindBin;
use lib "$FindBin::Bin/lib";


use Test::More;

use SPVM 'TestCase::Webkit::URL';

# Start objects count
my $start_memory_blocks_count = SPVM::get_memory_blocks_count();

# SPVM::Webkit::URL
{
  ok(SPVM::TestCase::Webkit::URL->test_parse_escape_all);
  ok(SPVM::TestCase::Webkit::URL->test_parse_host);
  ok(SPVM::TestCase::Webkit::URL->test_parse_host_path);
  ok(SPVM::TestCase::Webkit::URL->test_parse_host_params);
  ok(SPVM::TestCase::Webkit::URL->test_parse_host_fragment);
  ok(SPVM::TestCase::Webkit::URL->test_parse_host_path_fragment);
  ok(SPVM::TestCase::Webkit::URL->test_not_found_scheme_separator);
  ok(SPVM::TestCase::Webkit::URL->test_amazon_path_escaped);
  ok(SPVM::TestCase::Webkit::URL->test_host_is_not_for_url);
  ok(SPVM::TestCase::Webkit::URL->test_trailing_slash);
}

# All object is freed
my $end_memory_blocks_count = SPVM::get_memory_blocks_count();
is($end_memory_blocks_count, $start_memory_blocks_count);

done_testing;
