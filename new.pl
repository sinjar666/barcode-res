#my $var="({1,1}[0-9]{13,13}){1,1}$";
my $str="skfjdn;f fnojednfiJNDFIJDFN JFO(NDOIN_)(1234676890123)";
if($str=~m/\({1,1}[0-9]{13,13}\){1,1}$/)
{
 print 1;
}
else {
 print 0;
}

