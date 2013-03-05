CREATE TABLE User (
       Id integer PRIMARY KEY,
       Username varchar(30),
       Password varchar(30)
);

CREATE TABLE Contact (
       Id integer PRIMARY KEY,
       Id_User integer REFERENCES User(Id),
       Pseudo varchar(30),
       IP varchar(30)
);

CREATE TABLE Conversation (
       Id integer PRIMARY KEY,
       Id_User integer REFERENCES User(Id)
);

CREATE TABLE Conversation_History (
       Id_Conversation integer REFERENCES Conversation(Id),
       Date Date,
       Username varchar(30),
       Content TEXT
);

CREATE TABLE Conversation_Member (
       Id_Conversation integer REFERENCES Conversation(Id),
       Username varchar(30),
       IP varchar(30)
);

