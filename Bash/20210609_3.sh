#!/bin/bash

member=0
MAX_MEMBERS_COUNT=3
member_count=1
teams_count=11
count_teams=1
TEAM_MAX_COUNT=11
while [ "$count_teams" -le $TEAM_MAX_COUNT ]
do
	printf "Team $count_teams\n"
	while [ "$member_count" -le $MAX_MEMBERS_COUNT ]
	do
		member=$(((RANDOM%32)+1))
		echo "$member"
		let "member_count += 1"  
	done
	let "count_teams +=1"
done
