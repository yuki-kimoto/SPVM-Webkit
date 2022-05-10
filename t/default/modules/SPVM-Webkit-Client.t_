use lib "t/lib";
use TestAuto;

use strict;
use warnings;

use Test::More;
use TestFile;

use SPVM 'TestCase::Lib::Webkit::Client';

# Copy test_files to test_files_tmp with replacing os newline
TestFile::copy_test_files_tmp_replace_newline();

# Start objects count
my $start_memory_blocks_count = SPVM::get_memory_blocks_count();

# Webkit::Client
{
  ok(SPVM::TestCase::Lib::Webkit::Client->test_get);
  ok(SPVM::TestCase::Lib::Webkit::Client->test_head);
  ok(SPVM::TestCase::Lib::Webkit::Client->test_post);
  ok(SPVM::TestCase::Lib::Webkit::Client->test_post_form);
  ok(SPVM::TestCase::Lib::Webkit::Client->test_post_form_syntax_sugar);
  ok(SPVM::TestCase::Lib::Webkit::Client->test_get_chunk_small);
  ok(SPVM::TestCase::Lib::Webkit::Client->test_get_chunk_large);
}


# All object is freed
my $end_memory_blocks_count = SPVM::get_memory_blocks_count();
is($end_memory_blocks_count, $start_memory_blocks_count);

done_testing;
