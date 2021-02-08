drop table Employe cascade constraints;
drop table Projet cascade constraints;
drop table Embauche cascade constraints;
drop table Grille_sal cascade constraints;
purge recyclebin;

@TME8-creations


insert into Employe (NumSS, NomE, PrenomE, VilleE, DateNaiss)
select * from (
       select	22334, 'Adam', 'Funk', 'Paris', '1-12-1982'		from dual union all
       select	45566, 'Rachid', 'Allaoui', 'Lyon', '13-4-1986'	     	from dual union all
       select	77889, 'Florent', 'Girac' , 'Marseille', '4-11-1990'	from dual union all
       select 	90011, 'Mayla', 'Aoun', 'Lyon', '26-3-1987'		from dual union all
       select	22233, 'Christine', 'Lara', 'Paris', '9-8-1982'		from dual union all
       select	34445, 'Amel', 'Orlando', 'Lyon', '14-2-1976'		from dual union all
       select	55666, 'Mohsen', 'Charef', 'Paris', '28-5-1991'		from dual union all
       select	77788, 'Tim', 'Arabi', 'Marseille', '8-6-1984'		from dual union all
       select	89990, 'Fernando', 'Lopez', 'Lyon', '5-10-1993'		from dual union all
       select	11122, 'Ada','Tan Lee', 'Marseille', '21-3-1994'	from dual
);


insert into Projet values (123, 'ADOOP', 22334, 'Paris', 120000);
insert into Projet values (757, 'SKALA', 45566, 'Lyon', 180000);
insert into Projet values (890, 'BAJA', 22334, 'Paris', 24000);


insert into grille_sal values ('Admin', 80000);
insert into grille_sal values ('Deve',45000);
insert into grille_sal values ('Tech',35000);

insert into Embauche values (77889, 123, '1-3-2014','Deve');
insert into Embauche values (90011, 123, '1-5-2014','Tech');
insert into Embauche values (22233, 757, '1-3-2014','Deve');