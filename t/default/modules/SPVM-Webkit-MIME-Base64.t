use lib "t/lib";
use TestAuto;

use strict;
use warnings;

use Test::More 'no_plan';

use SPVM 'TestCase::Lib::SPVM::Webkit::MIME::Base64';

# Start objects count
my $start_memory_blocks_count = SPVM::get_memory_blocks_count();

# SPVM::Webkit::MIME
{
  ok(TestCase::Lib::SPVM::Webkit::MIME::Base64->test_basic());
  ok(TestCase::Lib::SPVM::Webkit::MIME::Base64->test_all());
}

# All object is freed
my $end_memory_blocks_count = SPVM::get_memory_blocks_count();
is($end_memory_blocks_count, $start_memory_blocks_count);
