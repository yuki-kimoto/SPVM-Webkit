use lib "t/lib";
use TestAuto;

use strict;
use warnings;

use Test::More 'no_plan';

use SPVM 'TestCase::Lib::SPVM::Webkit::URL::Parameters';

# Start objects count
my $start_memory_blocks_count = SPVM::get_memory_blocks_count();

# SPVM::Webkit::URL::Parameters
{
  ok(TestCase::Lib::SPVM::Webkit::URL::Parameters->test_escape);
  ok(TestCase::Lib::SPVM::Webkit::URL::Parameters->test_parse);
  ok(TestCase::Lib::SPVM::Webkit::URL::Parameters->test_add_get);
  ok(TestCase::Lib::SPVM::Webkit::URL::Parameters->test_keys);
}

# All object is freed
my $end_memory_blocks_count = SPVM::get_memory_blocks_count();
is($end_memory_blocks_count, $start_memory_blocks_count);
