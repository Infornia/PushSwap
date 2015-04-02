# PushSwap

This are empiric tests I did, if wanna know how I proceeded:

2 Arguments:
	1 2		end
	2 1		rb

1 2 3		nb < < End

1 3 2		nb < <
			rra		2 1 3
					sa

2 1 3		nb > <
			sa

2 3 1		nb < >
			rra

3 1 2		nb > >
			ra

3 2 1		nb > >
			ra		2 1 3
					sa


1 2 3 4		end

1 2 4 3		nb < < && nb+1 < <
			pb rra sa pa

1 3 2 4		nb < < && nb+1 > <
			pb sa pa

1 3 4 2		nb < < && nb+1 < >
			pb rra pa

1 4 2 3		nb < < && nb+1 > >
			pb ra pa

1 4 3 2		nb < < && nb+1 > >
			pb ra sa pa

4 3 2 1		nb > > && nb+1 > >
			ra		3 2 1 4
					sa		2 3 1 4
							pb		3 1 4
									sa		1 3 4
											pb		3 4 ; 1	2
													rb		3 4 ; 2 1
															pa pa
			ra ra		2 1 4 3
						pb pb	4 3 ; 1 2
								rr	3 4 ; 2 1
									pa pa
			rra pb	4 3 2 ; 1
					rra pb	4 3 ; 2 1
							ra pa pa

4312	nb > > && nb+1 > >

4231	nb > > && nb+1 < >

4213	nb > > && nb+1 > <

4123	nb > > && nb+1 < <

4132	nb > > && nb+1 < <




1 2 3 4 5

1 5 3 2 4	nb < < &&  nb+1 > >
			pb		5 3 2 4
					ra		3 2 4 5
							sa		2 3 4 5
									pa		1 2 3 4 5


A checker
		2 1 3 6 5 8
		1 2 5 9 8 7 4 10 3 11 13 14 12
		4 10 3 11 13 14 12
		1 2 3 4 6 5
