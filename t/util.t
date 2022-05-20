use strict;
use warnings;
use FindBin;
use lib "$FindBin::Bin/lib";
use Encode 'encode';
use utf8;

use Test::More;

use SPVM 'TestCase::Webkit::Util';

# Start objects count
my $start_memory_blocks_count = SPVM::get_memory_blocks_count();

subtest 'url_escape' => sub {
  is(SPVM::Webkit::Util->url_escape('business;23'), 'business%3B23', 'right URL escaped result');
};

subtest 'url_escape (nothing to escape)' => sub {
  is(SPVM::Webkit::Util->url_escape('foobar123-._~'), 'foobar123-._~', 'no changes');
};

subtest 'UTF-8 url_escape' => sub {
  is(SPVM::Webkit::Util->url_escape("fooあbarい"), 'foo%E3%81%82bar%E3%81%84',
    'right URL escaped result');
};

# All object is freed
my $end_memory_blocks_count = SPVM::get_memory_blocks_count();
is($end_memory_blocks_count, $start_memory_blocks_count);

done_testing;
