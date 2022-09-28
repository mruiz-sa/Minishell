# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_minishell.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manu <manu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 19:35:22 by manu              #+#    #+#              #
#    Updated: 2022/09/28 19:35:23 by manu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Based on dgerwig-'s awesome implementation!!

BOLDRED="\033[1m\033[31m"
BOLDGREEN="\033[1m\033[32m"
RED="\033[0m\033[31m"
GREEN="\033[0m\033[32m"
YELLOW="\033[0m\033[33m"
BLUE="\033[0m\033[34m"
MAGENTA="\033[0m\033[35m"
CYAN="\033[0m\033[36m"
RESET="\033[0m"

TOTAL=0
CORRECT=0

FAILED=0       #print only failed tests: value FAILED=1

clear
printf "$MAGENTA\n"
printf "==========================================\n"
printf "            MINISHELL TESTER              \n"
printf "==========================================\n"
printf "$RESET\n"

printf "⚠️  Select TYPE TEST --> all / simple \n\n"
read -p "Enter command: " command
while [ "$command" != "all" ] && 
	[ "$command" != "simple" ]
do
	printf "\n‼️  WRONG USE. Use a valid TYPE TEST\n"
	printf "⚠️  Select TYPE TEST --> all / simple \n\n"
	read -p "Enter command: " command
done
printf "\n"

exec_test_cmp_vs_bash()
{
	echo $@ | ./minishell | tail -n +2 > test1
	echo $@ | /bin/bash > test2 
	test1="test1"
	test2="test2"
	compare_files "$@" 
}

compare_files()
{
	if (cmp -s  "$test1" "$test2") ; then
		if [ $FAILED -eq 1 ]; then
		CORRECT=$(( $CORRECT + 1 ))
		else
		CORRECT=$(( $CORRECT + 1 ))
		printf $CYAN"Test nº: %.3d \t$RESET" "$(($TOTAL + 1))" 
		printf $BOLDGREEN"✅ Right! $GREEN %s $RESET\n" "$@"
		printf $YELLOW"minishell output: \n$BLUE"
		echo $@ | ./minishell
		printf $YELLOW"bash output: \n$BLUE"
		echo $@ | /bin/bash
		printf $YELLOW"\nTEST minishell output: \n%.40s\n$(cat -e test1)\n%.40s$RESET\n" "=========================================" "========================================="
		printf $GREEN"TEST bash output: \n%.40s\n$(cat -e test2)\n%.40s$RESET\n" "=========================================" "========================================="
		printf "$RESET\n"
		fi
	else
		printf $CYAN"Test nº: %.3d \t$RESET" "$(($TOTAL + 1))" 
		printf $BOLDRED"❌ Error! %s %s$RESET\n" "$@"
		printf $YELLOW"minishell output: \n$BLUE"
		echo $@ | ./minishell
		printf $YELLOW"bash output: \n$BLUE"
		echo $@ | /bin/bash
		printf "$RESET"
		printf $YELLOW"\nTEST minishell output: \n%.40s\n$(cat -e test1)\n%.40s$RESET\n" "=========================================" "========================================="
		printf $GREEN"TEST bash output: \n%.40s\n$(cat -e test2)\n%.40s$RESET\n" "=========================================" "========================================="
		printf $RED"TEST diff minishell vs bash output: \n%.40s\n$(diff test1 test2)\n%.40s$RESET\n\n" "=========================================" "========================================="
	rm -rf test1 test2
	fi
	TOTAL=$(($TOTAL + 1))
}

print_result()
{
	if [ $CORRECT -eq $TOTAL ]; then
		printf "\n$BOLDGREEN"
	else
		printf "\n$BOLDRED"
	fi
	printf "%s: %d/%d passed tests (%0.2f%%)\n\n$RESET" "$command" "$CORRECT" "$TOTAL" "$(($CORRECT * 100 / $TOTAL))"
}

# SIMPLE
if [ "$command" = "simple" ] || [ "$command" = "all" ] ; then
	printf "$CYAN\n"
	printf "******************************************\n"
	printf "         TYPE TEST: simple\n"
	printf "******************************************\n"
	printf "$RESET\n"
	exec_test_cmp_vs_bash "ls src -la"
	print_result
fi
rm -rf test1 test2
