use strict;
use warnings;
use FindBin;
use lib "$FindBin::Bin/lib";


use Test::More;

use SPVM 'TestCase::Webkit::URL::Parameters';

# Start objects count
my $start_memory_blocks_count = SPVM::get_memory_blocks_count();

# SPVM::Webkit::URL::Parameters
{
  ok(SPVM::TestCase::Webkit::URL::Parameters->test_escape);
  ok(SPVM::TestCase::Webkit::URL::Parameters->test_parse);
  ok(SPVM::TestCase::Webkit::URL::Parameters->test_add_get);
  ok(SPVM::TestCase::Webkit::URL::Parameters->test_keys);
}

# All object is freed
my $end_memory_blocks_count = SPVM::get_memory_blocks_count();
is($end_memory_blocks_count, $start_memory_blocks_count);

done_testing;
