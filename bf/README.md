## How i solved my bf project

### ASCII VALUE:
a = 97 and the rest of the alphabet is gotten by incrementing a i.e adding one to a to get the next.

To get the value of a CAPITAL letter, minus 32 from it's ASCII value
we have 's' which is 115. To get "S", 115 - 32 = 83


so the first 10 '+', are 83/10 which is 8.3

so we have 1 '+': ++++++++++
now another cell of a loop, i used '>' to tell it to jumo to the next incrementation, which is 8, then used '<' so the loop doesn't go out of range,
then - to get '8' and move to the next cell using '>' and added 3 '+' and a . to print the result. That leaves us with this:

	++++++++++	[	>	++++++++		<	-	]	>	+++	.
	^		^	^	^			^	^	^	^	^	^
	dividend	start	jump	8 '+' also		range	decrease end	jump	3 '+'	print	
	also '10' 	loop	to	first 8 when i		guard	back	of
				next	divided by 10			to	loop
				cell					8

	
