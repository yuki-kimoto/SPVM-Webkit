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

{
  is(SPVM::Webkit::Util->url_escape('business;23'), 'business%3B23');
};

{
  is(SPVM::Webkit::Util->url_escape('foobar123-._~'), 'foobar123-._~');
};

{
  is(SPVM::Webkit::Util->url_escape("fooあbarい"), 'foo%E3%81%82bar%E3%81%84');
};

{
  is(SPVM::Webkit::Util->url_unescape('business%3B23'), 'business;23');
};

{
  is(SPVM::Webkit::Util->url_unescape('foobar123-._~'), 'foobar123-._~');
};

{
  is(SPVM::Webkit::Util->url_unescape('foo%E3%81%82bar%E3%81%84'), "fooあbarい");
};


# All object is freed
my $end_memory_blocks_count = SPVM::get_memory_blocks_count();
is($end_memory_blocks_count, $start_memory_blocks_count);

done_testing;
