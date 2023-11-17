-- Keep a log of any SQL queries you execute as you solve the mystery.

select description from crime_scene_reports where year=2021 and month=7 and day=28 and street= 'Humphrey Street';
select name, transcript from interviews where year=2021 and month=7 and day=28;

--ruth bakery parking
--eugene ATM
--raymond phone call- flight to fiftyville

select name from people
join bank_accounts on people.id = bank_accounts.person_id
join atm_transactions on bank_accounts.account_number = atm_transactions.account_number
where atm_transactions.year = 2021 and atm_transactions.month = 7 and atm_transactions.day = 28
and atm_transactions.atm_location like 'Leggett Street'
and atm_transactions.transaction_type like 'withdraw'
order by name;

-- ATM
-- Benista - Brooke - Bruce - Diana - Iman - kenny - Luca - Taylor

select flights.id, city, flights.hour, flights.minute from airports
join flights on airports.id = flights.destination_airport_id
where flights.origin_airport_id = (select id from airports where city like 'Fiftyville')
and flights.year = 2021 and flights.month = 7 and flights.day = 29
order by flights.hour, flights.minute;

select name from people
join passengers on people.passport_number = passengers.passport_number
join flights on passengers.flight_id = flights.id
where flights.year = 2021 and flights.month = 7 and flights.day = 29
and flights.origin_airport_id = (select id from airports where city like 'Fiftyville')
and flights.destination_airport_id = (select id from airports where city like 'New York City')
order by name;

-- flight
--Bruce - Doris - Edward - Kelsey - Kenny - Luca - Sofia - Taylor

select name, phone_calls.duration from people
join phone_calls on people.phone_number = phone_calls.caller
where phone_calls.year = 2021 and phone_calls.month = 7 and phone_calls.day = 28
and phone_calls.duration <=60
order by name;

-- phone calls caller
-- Benista 54 - Bruce 45 - Carina 38 - Diana 49 - Kathryn 60 - Kelsey 36 - Kelsey 50 - Kenny 55 - Sofia 51 - Taylor 43

select name, phone_calls.duration from people
join phone_calls on people.phone_number = phone_calls.receiver
where phone_calls.year = 2021 and phone_calls.month = 7 and phone_calls.day = 28
and phone_calls.duration <=60
order by name;

-- phone calls receiver
-- Anna 54 - Doris 55 - Jack 51 - Jacqueline 38 - James 43 - Larry 36 - Luca 60 - Mellisa 50 - Philip 49 - Robin 45

select name from people
join bakery_security_logs on people.license_plate = bakery_security_logs.license_plate
where bakery_security_logs.year = 2021
and bakery_security_logs.month = 7
and bakery_security_logs.day = 28
and bakery_security_logs.activity = 'exit'
and bakery_security_logs.hour = 10
and bakery_security_logs.minute >= 15
and bakery_security_logs.minute <= 25
order by name;

-- parking log
-- Barry - Bruce - Diana - Iman - Kelsey - Luca - Sofia - Venessa



-- find rubber
-- ATM
-- Benista - Brooke - Bruce - Diana - Iman - kenny - Luca - Taylor
-- flight
--Bruce - Doris - Edward - Kelsey - Kenny - Luca - Sofia - Taylor
-- phone calls caller
-- Benista 54 - Bruce 45 - Carina 38 - Diana 49 - Kathryn 60 - Kelsey 36 - Kelsey 50 - Kenny 55 - Sofia 51 - Taylor 43
-- parking log
-- Barry - Bruce - Diana - Iman - Kelsey - Luca - Sofia - Venessa
