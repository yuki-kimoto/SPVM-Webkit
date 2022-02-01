use 5.008007;
use strict;
use warnings;
use ExtUtils::MakeMaker;
use SPVM::Builder::Util::API;

WriteMakefile(
    NAME             => 'SPVM::Webkit',
    AUTHOR           => q{Yuki Kimoto <kimoto.yuki@gmail.com>},
    VERSION_FROM     => 'lib/SPVM/Webkit.pm',
    ABSTRACT_FROM    => 'lib/SPVM/Webkit.pm',
    LICENSE          => 'artistic_2',
    PL_FILES         => {},
    MIN_PERL_VERSION => '5.008007',
    CONFIGURE_REQUIRES => {
        'ExtUtils::MakeMaker' => '0',
    },
    BUILD_REQUIRES => {
        'Test::More' => '0',
    },
    PREREQ_PM => {
        SPVM => 0.9500,
    },
    dist  => { COMPRESS => 'gzip -9f', SUFFIX => 'gz', },
    clean => { FILES => 'SPVM-Webkit-*' },
    test => {TESTS => 't/*.t t/*/*.t t/*/*/*.t'},
);

# Add Build shared library make rule
sub MY::postamble {

  my $make_rule = '';
  
  # Native compile make rule
  $make_rule .= SPVM::Builder::Util::API::create_make_rule_native('Webkit::MIME::Base64');
  $make_rule .= SPVM::Builder::Util::API::create_make_rule_native('Webkit::Socket');
  $make_rule .= SPVM::Builder::Util::API::create_make_rule_native('Webkit::Select');
  $make_rule .= SPVM::Builder::Util::API::create_make_rule_native('Webkit::Time');
  
  return $make_rule;
}
