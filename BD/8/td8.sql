CREATE table EMPLOYE(
    NumSS number(5) check(length(NumSS)=5), 
    NomE varchar(20), 
    PrenomE varchar(20), 
    NumChef number(5) check(length(NumChef)=5), 
    VilleE varchar(9) check(lower(VilleE) in ('paris','lyon','marseille')), 
    DateNaiss date, 
    DateEnreg date Default sysdate,

    primary key(NumSS),
    foreign key (NumChef) references EMPLOYE(NumSS),
    unique(NomE,PrenomE),

    /*constraint moins_que_70*/
    check(DateEnreg-DateNaiss<=70)
    /*(DATEDIFF(year,DateNaiss,dateEnreg)<=70.0)*/
);

CREATE table PROJET(
    NumProj Number(7) check (length(NumProj) >=5), 
    NomProj varchar(20), 
    RespProj number(5) not null check (length(RespProj)=5),
    VilleP varchar(9) check(lower(VilleP) in ('paris','lyon','marseille')), 
    Budget number(6),
    primary key(NumProj),
    foreign key (RespProj) references EMPLOYE(NumSS)
);

CREATE table GRILLE_SAL(
    Profil varchar(20), 
    salaire numeric(7,2) check(salaire<90000),
    primary key(Profil)
);

CREATE table EMBAUCHE(
    NumSS int, 
    NumProj int, 
    DateEmb date default sysdate, 
    Profil varchar(20),
    primary key(NumSS,NumProj),
    foreign key (NumSS) references EMPLOYE,
    foreign key (NumProj) references PROJET,
    foreign key (Profil) references GRILLE_SAL
);

/*
create assertion meme_ville
    check(NOT EXISTS(
        SELECT * FROM PROJET,EMPLOYE
        WHERE VilleP<>VillE AND RespProj=NumSS
));

create assertion est_dans 
    check(NOT EXISTS(
        SELECT * FROM EMPLOYE,PROJET
        WHERE NumChef NOT IN(SELECT NumSS FROM EMPLOYE)
        OR RespProj NumChef NOT IN(SELECT NumSS FROM EMPLOYE)
));

create assertion est_dans 
    check(NOT EXISTS(
        SELECT * FROM EMBAUCHE eb, EMPLOYE ep, PROJET pj, GRILLE_SAL pf
        WHERE eb.NumSS<>ep.NumSS OR eb.NumProj<>pj.NumProj OR eb.Profil<>pf.Profil
));
*/

create domain C1 as number(5) check (length(value)=5); 
/*create domain C1 as number(5) check(value>=10000);*/
create domain C2 as varchar(20);
create domain C3 varchar(9) check (lower(value) in ('paris', 'lyon', 'marseille'));

create table Employe(
NumSS C1, 
NomE C2, 
PrenomE C2, 
NumChef C1, 
VilleE C3,
DateNaiss date ,
DateEnreg date default sysdate, 
etc.
);

constraint chef_in_city  check (
    exists (  	
        select * from EMPLOYE e  	
        where RespProj = e.NumSS 
        and e.VilleE = VilleP  	)  )