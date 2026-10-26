 -- Q1 (i)
CREATE DATABASE IF NOT EXISTS insurance_db;
USE insurance_db;

-- Q1 (ii)
CREATE TABLE PERSON (
    driver_id VARCHAR(20) PRIMARY KEY,
    name VARCHAR(50),
    address VARCHAR(100)
);

CREATE TABLE CAR (
    regno VARCHAR(20) PRIMARY KEY,
    model VARCHAR(50),
    year DATE
);

CREATE TABLE ACCIDENT (
    report_number INT PRIMARY KEY,
    accdate DATE,
    location VARCHAR(50)
);

CREATE TABLE OWNS (
    driver_id VARCHAR(20),
    regno VARCHAR(20),
    PRIMARY KEY (driver_id, regno)
);

CREATE TABLE PARTICIPATED (
    driver_id VARCHAR(20),
    regno VARCHAR(20),
    report_number INT,
    damage_amount INT,
    PRIMARY KEY (driver_id, regno, report_number)
);

-- Q1 (iii)
ALTER TABLE OWNS
ADD FOREIGN KEY (driver_id)
REFERENCES PERSON(driver_id);

ALTER TABLE OWNS
ADD FOREIGN KEY (regno)
REFERENCES CAR(regno);

ALTER TABLE PARTICIPATED
ADD FOREIGN KEY (driver_id, regno)
REFERENCES OWNS(driver_id, regno);

ALTER TABLE PARTICIPATED
ADD FOREIGN KEY (report_number)
REFERENCES ACCIDENT(report_number);

-- Q1 (iv)
DESC PERSON;
DESC CAR;
DESC ACCIDENT;
DESC OWNS;
DESC PARTICIPATED;

-- Q1 (v)
INSERT INTO PERSON VALUES
('1', 'Ananth', 'Kandy'),
('2', 'Bala', 'Batticaloa'),
('3', 'Carol', 'Mannar');

INSERT INTO CAR VALUES
('1001', 'BMW', '2010-01-12'),
('1002', 'BENZ', '2008-03-12'),
('1003', 'BENZ', '2008-06-14');

INSERT INTO ACCIDENT VALUES
(1111, '2011-01-12', 'Kandy'),
(2222, '2011-03-12', 'Batticaloa'),
(3333, '2011-03-12', 'Batticaloa'),
(4444, '2008-01-12', 'Kandy');

INSERT INTO OWNS VALUES
('1', '1001'),
('2', '1002'),
('3', '1003');

INSERT INTO PARTICIPATED VALUES
('1', '1001', 1111, 20000),
('2', '1002', 2222, 40000),
('3', '1003', 3333, 20000);

-- Q1 (vi)
UPDATE PARTICIPATED
SET damage_amount = 25000
WHERE regno = '1002'
AND report_number = 2222;

-- Q1 (vii)
SELECT COUNT(DISTINCT model)
FROM CAR;

-- Q1 (viii)
SELECT COUNT(*)
FROM ACCIDENT
WHERE location = 'Batticaloa'
AND YEAR(accdate) = 2011;

-- Q1 (ix)
SELECT COUNT(DISTINCT O.driver_id)
FROM OWNS O
JOIN PARTICIPATED P
ON O.driver_id = P.driver_id
AND O.regno = P.regno
JOIN ACCIDENT A
ON P.report_number = A.report_number
WHERE YEAR(A.accdate) = 2011;

-- Q1 (x)
SELECT COUNT(DISTINCT P.report_number)
FROM CAR C
JOIN PARTICIPATED P
ON C.regno = P.regno
WHERE C.model = 'BMW';

-- Q1 (xi)
-- Run in Windows Command Prompt, not MySQL console:
-- mysqldump -u root -p insurance_db > insurance_db.sql
