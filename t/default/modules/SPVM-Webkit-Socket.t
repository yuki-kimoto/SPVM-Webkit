use lib "t/lib";
use TestAuto;

use strict;
use warnings;

use Test::More;

use SPVM 'TestCase::Lib::Webkit::Socket';

# Start objects count
my $start_memory_blocks_count = SPVM::get_memory_blocks_count();

# Socket
{
  ok(SPVM::TestCase::Lib::Webkit::Socket->basic);
  ok(SPVM::TestCase::Lib::Webkit::Socket->basic_auto_close);
  ok(SPVM::TestCase::Lib::Webkit::Socket->fileno);
}


# All object is freed
my $end_memory_blocks_count = SPVM::get_memory_blocks_count();
is($end_memory_blocks_count, $start_memory_blocks_count);

done_testing;
