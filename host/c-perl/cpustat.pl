#!/usr/bin/env perl
use strict;
use warnings;
use feature 'say';
use Time::HiRes 'usleep';

sub get_cpu_stat {
        my $stat='';
        open(my $fh,'<','/proc/stat') || die $!;
        local $/; $stat=<$fh>;
        my ($user,$nice,$system,$idle)=($1,$2,$3,$4) if ($stat=~/cpu\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+/);
        return $user+$nice+$system,$idle;
}

while(1){
	my ($cput1,$idle1)=get_cpu_stat();
	# usleep(500*1000);
	usleep(300*1000);
	my ($cput2,$idle2)=get_cpu_stat();
	my $cput3=$cput2-$cput1;
	my $idle3=$idle2-$idle1;

	my $cpup=$cput3 / ($cput3+$idle3);

	my $val = int(255*$cpup);
	$val=254 if($val > 255);
	system('./sender','/dev/ttyUSB0','1',$val);

	# say sprintf('% 8.2f%% (% 3d)',$cpup*100,$val);
}
