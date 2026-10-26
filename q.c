 -- Q1 (i)
CREATE DATABASE hospital_db;

-- Q1 (iii)
USE hospital_db;
.........
 CREATE TABLE PATIENT (
    patientno INT PRIMARY KEY,
    pname VARCHAR(100),
    city VARCHAR(100),
    phone VARCHAR(20)
);
..................
CREATE TABLE DOCTOR (
    doctorno INT PRIMARY KEY,
    dname VARCHAR(100),
    specialization VARCHAR(100)
);
....................
CREATE TABLE WARD (
    wardno INT PRIMARY KEY,
    wardname VARCHAR(100),
    city VARCHAR(100)
);
.................
CREATE TABLE APPOINTMENT (
    appointmentno INT PRIMARY KEY,
    appointment_date DATE,
    patientno INT,
    doctorno INT,
    FOREIGN KEY (patientno)
        REFERENCES PATIENT(patientno),
    FOREIGN KEY (doctorno)
        REFERENCES DOCTOR(doctorno)
);
.....................
  CREATE TABLE ADMISSION (
    admissionno INT PRIMARY KEY,
    patientno INT,
    wardno INT,
    admission_date DATE,
    discharge_date DATE,
    FOREIGN KEY (patientno)
        REFERENCES PATIENT(patientno),
    FOREIGN KEY (wardno)
        REFERENCES WARD(wardno)
);  
.............
 CREATE TABLE TREATMENT (
    treatmentno INT PRIMARY KEY,
    appointmentno INT,
    description VARCHAR(255),
    cost INT,
    FOREIGN KEY (appointmentno)
        REFERENCES APPOINTMENT(appointmentno)
);
...................

 (v)
  SHOW TABLES;
....
DESC PATIENT;
....
 DESC DOCTOR;
....
 DESC WARD;
....
 DESC APPOINTMENT;
.....
 DESC ADMISSION;
....
 DESC TREATMENT;

...................................
 (vii)
 UPDATE PATIENT
SET pname = 'Roshan'
WHERE patientno = 101;
.............................
 (viii)
 SELECT *
FROM PATIENT
WHERE city = 'Batticaloa';
...............................
 (ix)
 SELECT *
FROM PATIENT
WHERE city = 'Batticaloa'
   OR city = 'Jaffna';
..................................
 (x)
 SELECT *
FROM TREATMENT
WHERE cost > 50000;
....................................
 (xi)
 SELECT DISTINCT p.pname
FROM PATIENT p
INNER JOIN APPOINTMENT a
    ON p.patientno = a.patientno
INNER JOIN TREATMENT t
    ON a.appointmentno = t.appointmentno
WHERE t.cost > 50000;
.....................................
 (xii)
 SELECT DISTINCT p.pname
FROM PATIENT p
INNER JOIN ADMISSION a
    ON p.patientno = a.patientno
INNER JOIN WARD w
    ON a.wardno = w.wardno
WHERE p.city = w.city;
......................................
 (xiii)
 SELECT COUNT(*) AS total_wards
FROM WARD
WHERE city = 'Colombo';
........................................
 (xiv)
 SELECT
    CASE
        WHEN COUNT(*) = 0 THEN 'YES'
        ELSE 'NO'
    END AS valid_dates
FROM ADMISSION
WHERE discharge_date < admission_date
   OR discharge_date IS NULL
   OR admission_date IS NULL;
 
  
