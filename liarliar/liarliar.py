#!/usr/bin/env python
import re
num = raw_input()
users = {}
for i in range(int(num)):
	line = raw_input()
	user = re.split('\s+',line)
	username = user[0]
	if not users.has_key(username):
		users[username] = "T"
	for j in range(int(user[1])):
		u = raw_input()
		if users[username] == "T":
			users[u] = "L"
		else:
			users[u] = "T"

L= 0
T = 0
for k,v in users.items():
	if v == "L": 
		L += 1
	else:
		T += 1

if L > T:
	print L, T
else:
	print T, L
