use lib "t/lib";
use TestAuto;

use strict;
use warnings;

use Test::More;

use SPVM 'TestCase::Lib::Webkit::Select';

# Start objects count
my $start_memory_blocks_count = SPVM::get_memory_blocks_count();

# Select
{
  ok(SPVM::TestCase::Lib::Webkit::Select->add);
  ok(SPVM::TestCase::Lib::Webkit::Select->remove);
  ok(SPVM::TestCase::Lib::Webkit::Select->exists);
  if ($^O ne 'MSWin32') {
    ok(SPVM::TestCase::Lib::Webkit::Select->can_read);
    ok(SPVM::TestCase::Lib::Webkit::Select->can_write);
    ok(SPVM::TestCase::Lib::Webkit::Select->has_exception);
  }
}

# All object is freed
my $end_memory_blocks_count = SPVM::get_memory_blocks_count();
is($end_memory_blocks_count, $start_memory_blocks_count);

done_testing;
