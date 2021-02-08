create table Employe(       
			NumSS	number(15)		, /*contrainte D1*/       
			NomE  	varchar2(20) NOT NULL	, /*contrainte D2*/       
			PrenomE	varchar2(20) NOT NULL	, /*contrainte D2*/       
			VilleE	varchar2(20) NOT NULL	, /*contrainte D2*/       
			DateNaiss date 	     NOT NULL	,      
			dateCour  date	     default sysdate,
					/*attribut superflu utile pour exprimer la contrainte C1*/       
			/*contraintes de cle et referentielles*/       
			constraint pk_emp
                		   primary key (NumSS),      
			/*contraintes generales*/       
			constraint limite_age       		  
                		   check ((dateCour-DateNaiss)/365<=70), 
			/*contraintes de domaine*/      
			constraint format_nss  
                		   check(length(NumSS)=5),
			constraint ville_emp      
                		   check (lower(villeE) in ('paris', 'lyon', 'marseille')) 		 
			); 


create  table Projet(      
			NumProj	Number(3),
			NomProj	varchar2(20)	NOT NULL,
			RespProj	number	NOT NULL,       
			VilleP	varchar2(20)	NOT NULL,       
			Budget		number,       
			/*contraintes de clés*/
			constraint pk_proj       		  
				primary key(numproj),       
			constraint fk_resp       		  
				foreign key (RespProj) references Employe,             
			constraint ville_proj       		  
				check (lower(villeP) in ('paris', 'lyon', 'marseille')),       
			constraint limite_budget       		  
				check (budget <1000000) 		  
		); 

create table Grille_sal(       
			profil	varchar2(20),       
			salaire	number(7,2)	NOT NULL,            
			 /*contraintes de clés*/
			constraint pk_sal  
                primary key (profil),
			 /*contraintes de domaine*/
			constraint sal_max 
                check (salaire<90000) 
			); 


create table Embauche(       
			NumSS	number ,
			NumProj	number ,       
			DateEmb	date default sysdate NOT NULL,       
			Profil	varchar2(20) NOT NULL,       
			/*contraintes de clés*/
     			constraint pk_emb primary key (NumSS, NumProj),
			constraint fk_emb_emp 
               			    foreign key (NumSS) references Employe,
			constraint fk_emb_proj 
               			    foreign key (NumProj) references Projet,
			constraint fk_emb_sal 
               			    foreign key (Profil) references Grille_sal	
			); 