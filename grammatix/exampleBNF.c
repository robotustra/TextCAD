input	::= ws expr ws eoi;

expr	::= ws powterm [{ws '^' ws powterm}];
powterm	::= ws factor [{ws ('*'|'/') ws factor}];
factor	::= ws term [{ws ('+'|'-') ws term}];
term	::= '(' ws expr ws ')' | '-' ws expr | number;

number	::= {dgt} ['.' {dgt}] [('e'|'E') ['-'] {dgt}];
dgt	::= '0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9';
ws	::= [{' '|'\t'|'\n'|'\r'}];