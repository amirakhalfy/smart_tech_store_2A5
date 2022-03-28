create sequence incremen
start with 1
increment by 1;

create or replace trigger trg_commande
before insert on COMMANDE
for each row 
begin
select incremen.nextval into :NEW.ID_COMMAND from DUAL;
end;
