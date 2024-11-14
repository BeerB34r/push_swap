# **************************************************************************** #
#                                                                              #
#                                                          ::::::::            #
#    notes.md                                            :+:    :+:            #
#                                                       +:+                    #
#    By: mde-beer <mde-beer@student.codam.nl>          +#+                     #
#                                                     +#+                      #
#    Created: 2024/11/14 20:18:53 by mde-beer       #+#    #+#                 #
#    Updated: 2024/11/14 20:40:57 by mde-beer       ########   odam.nl         #
#                                                                              #
# **************************************************************************** #

# TODO rewrite everything in robot.c to pass by _reference_, so as to actually
# change the stack

# notepad for push_swap

## mandatory survivors

	- thief_of_joy.c
		-	contains the functions that determine the behaviour of various
			chiral functions
	- accountancy.c
		-	contains the cost-calculating functions
	- init_stack.c
		-	initiaties the stack, contains all necessary logic to make sure no
			erroneous values are encountered throughout.
	- robot.c
		-	holds the two stacks, and calls the solving functions
	- curta.c
		-	will eventually hold the rotaty-keepy-tracky bits
	- instructions.c
		-	will eventually contain all the push_swap instruction functions

## mandatory thought process
any stack of size < 3 can be sorted in 2 moves or less, thus check for that,
early return-solve if true

start by pushing 3 items to b and make sure theyre sorted;
while a has more than 3 elements, push the cheapest value to b
then, if a has less than 3 elements, push until a has 3 elements precisely
solve the triplet a
while b has elements, push the cheapest to a
then, if a is not in the correct rotational position, rotate it until it is
return success

## bonus thought process

during the process of building the solving, i will be actually doing the
instructions to make sure the logic is sound, so i will just have the functions
lying about. making a barebones parser for shell input is dogshit easy, so
implementing the checker seems like a piece of cake. just use gnl a bit, and
then boom, crazy.
