% a simple prolog program
woman(pam).
woman(liz).
woman(ann).
woman(pat).
man(tom).
man(bob).
man(jim).
parent(pam,bob).
parent(tom,bob).
parent(tom,liz).
parent(bob,ann).
parent(bob,pat).
parent(pat,jim).
mother(X,Y):-woman(X),parent(X,Y).
grandmother(X,Y):- woman(X), parent(X,C),parent(C,Y).
father(X,Y):-man(X),parent(X,Y).
son(X,Y):- man(Y), parent(X,Y).
sister(X,Y):- woman(X),parent(G,X),parent(G,Y),not(X=Y).
