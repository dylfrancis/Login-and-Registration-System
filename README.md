# Login-and-Registration-System
A login and registration system programmed in C++ that utilizes password hashing so nobody but the user is able to see the password.

This program does the following:
1. Allows users to register a username, password, and security question into a database (text file)
2. Once registered, the user's password and security question will be hashed and nobody but the user will be able to know their password/security question
3. Using the text file, the user can login using their username and password
4. Once logged in, the user has a special game they may play
5. If a user forgets their password, there is a forget password option for the user which will ask for their username, and if it exists, the security question will be asked for. If the answer matches with what is in the database, the user will be able to use a new password.

Download the ZIP for all files to properly work.

Note: The main.exe and data.txt must be in the same folder for everything to work properly. If data.txt is not in the same folder, the executable will never be able to read user data
