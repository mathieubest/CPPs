# CPP Module 00

3 exercices where we learned:
- how to write to the console (ex00)
- how to create classes and headers in c++ (ex01 - ex02)

## Correction

All the exercices should be using the c++98

### *Ex00 (Megaphone)*
- check empty string
- write numbers and letters, with and without brackets

### *Ex01 (PhoneBook)*
- check the ctr+D and make sure the getline is protected
- check the arrows as an input (eventhought that doesn't change anything because it is still correct)
- make sure it is truncated if more then 10 characters

### *Ex02 (Accounts)*
- use a diff between both log but first process the files by skipping what is in the brackets []
- check how the timestamp was done
- command for processing the logs:
```sh
awk '{ sub (/^[^ ]* /, ""); print }' /path/to/logfile > processed_logfile.log
diff processed_logfile.log processed_mylogfile.log
```
