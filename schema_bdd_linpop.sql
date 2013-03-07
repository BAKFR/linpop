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

CREATE TABLE Logs (
	Id integer PRIMARY KEY,
	Id_Conv integer,
	Line text
);
