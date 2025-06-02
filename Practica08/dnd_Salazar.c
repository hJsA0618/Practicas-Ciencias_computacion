#include <stdio.h>
#include <string.h>

#define BUFFER 1024

typedef struct {
    char name[BUFFER];
    unsigned int level;
    char typeclass[BUFFER];
    unsigned int pointlife;
    unsigned int damage;
} personaje;

void levelup(personaje *p);
void printstats(personaje *p);
void combate(personaje *a, personaje *b);

void levelup(personaje *p) {
    if (p->level < 20) {
        p->level += 1;
//   <--------------incremento de vida ---------------------->
        if (strcmp(p->typeclass, "mago") == 0) {
            unsigned int increase = p->pointlife / 5;
            p->pointlife += increase;
        } else if (strcmp(p->typeclass, "bardo") == 0) {
            unsigned int increasee = p->pointlife / 3;
            p->pointlife += increasee;
        } else if (strcmp(p->typeclass, "luchador") == 0) {
            unsigned int increaseee = p->pointlife / 2;
            p->pointlife += increaseee;
        }
// <------------- incremento de daño ----------------------->
        if (strcmp(p->typeclass, "mago") == 0) {
            unsigned int increase = p->damage / 3;
            p->damage += increase;
        } else if (strcmp(p->typeclass, "bardo") == 0) {
            unsigned int increasee = p->damage / 4;
            p->damage += increasee;
        } else if (strcmp(p->typeclass, "luchador") == 0) {
            unsigned int increaseee = p->damage / 5;
            p->damage += increaseee;
        }
    }
}

void printstats(personaje *p) {
    printf("Nombre: %s\n", p->name);
    printf("Nivel: %u\n", p->level);
    printf("Clase: %s\n", p->typeclass);
    printf("Puntos de vida: %u\n", p->pointlife);
    printf("Damage: %u\n", p->damage);
    printf("--------------------\n");
}

void combate(personaje *a, personaje *b) {
    unsigned int turnos = 0;
    printf("¡Inicio del combate entre %s y %s!\n", a->name, b->name);

    while (a->pointlife > 0 && b->pointlife > 0) {
        turnos++;
        printf("%s ataca a %s por %u puntos de damage.\n", a->name, b->name, a->damage);
        if (b->pointlife < a->damage) {
            b->pointlife = 0;
        } else {
            b->pointlife -= a->damage;
        }
        if (b->pointlife == 0) {
            printf("%s gana en %u turnos.\n", a->name, turnos);
            return;
        }
        printf("%s ataca a %s por %u puntos de damage.\n", b->name, a->name, b->damage);
        if (a->pointlife < b->damage) {
            a->pointlife = 0;
        } else {
            a->pointlife -= b->damage;
        }
        if (a->pointlife == 0) {
            printf("%s gana en %u turnos.\n", b->name, turnos);
            return;
        }
    }
    printf("Empate despues de %u turnos.\n", turnos);
}

int main(void) {
//      <----------- en vez de personajes de dungeons and dragons use caballeros del zodiaco ------------>    
    personaje dohko = {"Dohko de Libra", 10, "luchador", 150, 20};
    personaje saga = {"Saga de Geminis", 19, "mago", 300, 60}; 
    personaje shaka = {"Shaka de Virgo", 19, "mago", 250, 45}; 
    personaje mu = {"Mu de Aries", 10, "mago", 110, 22};
    personaje camus = {"Camus de Acuario", 10, "mago", 120, 24};
    personaje shura = {"Shura de Capricornio", 10, "luchador", 140, 18};
    personaje aioria = {"Aioria de Leo", 15, "luchador", 135, 20};
    personaje milo = {"Milo de Escorpio", 7, "luchador", 130, 19};
    personaje afrodita = {"Afrodita de Piscis", 5, "luchador", 125, 17};
    personaje aioros = {"Aioros de Sagitario", 16, "luchador", 130, 21};
    personaje aldebaran = {"Aldebaran de Tauro", 12, "luchador", 145, 23};
    personaje deathmask = {"Deathmask", 6, "luchador", 120, 15};

    printf("Estadisticas de los personajes:\n");
    printstats(&dohko);
    printstats(&saga);
    printstats(&shaka);
    printstats(&mu);
    printstats(&camus);
    printstats(&shura);
    printstats(&aioria);
    printstats(&milo);
    printstats(&afrodita);
    printstats(&aioros);
    printstats(&aldebaran);
    printstats(&deathmask);

    combate(&saga, &shaka);

    return 0;
}
/*
⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜
⬜⬜⬜⬛🟨⬛⬜⬜⬜⬜⬛⬜⬜⬜⬛🟨⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜
⬜⬜⬜⬛🟨⬛⬜⬜⬜⬛🟨⬛⬜⬜⬛🟨⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜
⬜⬜⬜⬛🟨⬛⬜⬜⬜⬛🟨⬛⬛⬛⬛🟨⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜
⬜⬜⬛🟨🟨⬛⬜⬜⬛⬛🟨⬛⬜⬜⬛🟨⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜
⬜⬜⬛🟨⬛⬜⬜⬛⬜⬛🟨⬛⬜⬜⬜⬛🟨⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜
⬜⬜⬛🟨⬛⬜⬛⬜⬜⬜🟨⬛⬜⬜⬜⬛🟨⬛⬜⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜
⬜⬜⬛🟨⬛⬛⬜⬜⬜🟨🟨🟥⬛⬜⬜⬛🟨⬛⬜⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜
⬜⬜⬛🟨⬛⬛⬜⬜⬜🟨🟥🟥⬛⬜⬜⬛🟨⬛⬜⬜⬛⬜⬜⬜⬜⬜⬜⬜⬜
⬜⬜⬛🟨🟨⬛⬛⬜⬜🟨🟥🟥⬛⬜⬛🟨🟨⬛⬜⬜⬛⬜⬜⬜⬜⬜⬜⬜⬜
⬜⬜⬜⬛🟨🟨⬛⬜⬜🟥🟥⬛⬜⬛🟨🟨⬛⬜⬜⬜⬛⬜⬜⬜⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬛🟨⬛⬜⬜🟥🟥⬛⬜🟨🟨⬛⬛⬜⬜⬜⬛⬜⬜⬜⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬜⬛🟨⬛⬜🟥🟥⬛⬜⬛⬛⬛🟦⬛⬜⬜⬛⬜⬛⬜⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬜⬜⬛⬛⬜⬜🟥⬜⬛⬛⬛🟦🟦⬛⬜⬜⬛⬛🟦⬛⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬜⬜⬛⬛⬛⬜⬜⬛⬜⬜⬛⬜🟦⬛⬜⬛🟦🟦🟦🟦⬛⬜⬜⬜⬜
⬜⬜⬜⬜⬜⬜⬜⬛🟦⬛⬛🟦⬜⬜⬛🟦⬛⬜⬜⬛🟦🟦🟦🟦🟦⬛⬜⬜⬜
⬜⬜⬜⬜⬜⬜⬜⬛🏻🏻🏻🏻🏻🏻🏻⬛⬜⬜⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬜
⬜⬜⬜⬛⬛⬛⬛⬛⬛🏻🏻🏻🏻🟦🟦⬛⬜⬛⬜⬜⬜⬜⬜⬜⬜⬛⬜⬜⬜
⬜⬜⬛⬜⬜⬜⬜⬜⬜⬛🏻🏻🏻🏻⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬛⬜⬜⬜⬜
⬜⬜⬜⬛⬜⬜⬜⬜⬛⬜⬛⬛⬛⬛⬜⬜⬛⬜⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬛⬜⬜⬛🟨⬜⬜⬜⬜⬜🟨🟨⬛⬛⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬜⬛⬛⬛⬛🟨⬜⬜⬜🟨⬛⬛🟦⬛⬜⬜⬛🏻⬛⬜⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬜⬛🏻⬛🟦⬛🟨⬛🟨⬛🟦🟦🟦⬛⬛⬛🏻🏻⬛⬜⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬜⬜⬛⬛🟦🟦⬛⬛⬛🟦🟦🟦🟦⬛🏻🏻🏻🏻🏻⬛⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬜⬜⬛🏻⬛🟦🟦⬛🟦🟦🟦🟦⬛⬛⬛🏻🏻⬛🏻⬛⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬜⬜⬛🏻⬛🟦🟦🟦🟦🟦🟦⬛⬛⬛⬛🏻⬛🟥⬛⬛⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬜⬜⬛🏻⬛⬛⬛⬛⬛⬛⬛⬛🟨⬛⬛⬛🟥🟥🟥⬛⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬜⬜⬛⬛🟥⬛🟥⬛🟥⬛🟥🟥⬛🟨⬛⬛🟥🟥🟥⬛⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬜⬜⬛⬛🟥🟥⬛🟥⬛🟥🟥🟥⬛🟨⬛⬛🟥🟥🟥⬛⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬜⬜⬛⬛🟥🟥🟥⬛🟥🟥🟥🟥⬛⬛⬛⬛🟥🟥🟥⬛⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬜⬛⬛⬛🟥🟥⬛🟥⬛🟥🟥🟥⬛⬛🏻🏻⬛🟥⬛⬛⬜⬜⬜⬜⬜
⬜⬜⬛⬛⬛🏻⬛⬛🟥⬛🟥🟥🟥⬛🟥⬛🟦⬛🏻⬛🏻⬛🏻⬛⬜⬜⬜⬜⬜
⬜⬛🟨🟨⬛🏻⬛🟦⬛⬛🟥🟥🟥🟥⬛🟦🟦🟦⬛🏻🏻🏻⬛⬛⬜⬜⬜⬜⬜
⬛🟨🟨🟨🟨⬛⬛⬛🟦⬛🟥🟥🟥⬛🟦🟦🟦⬛🟦⬛⬛⬛⬛⬜⬜⬛⬛⬜⬜
⬜⬛🟨🟨🟨🟨⬛🟦⬛🟦⬛⬛⬛🟦🟦🟦⬛🟦⬛🟥⬛🟨🟨⬛⬛🟨🟨⬛⬜
⬜⬜⬛🟨🟨⬛⬛🟦⬛🟦🟦🟦⬛🟦🟦🟦⬛🟦⬛🟥⬛⬛🟨🟨🟨🟨🟨🟨⬛
⬜⬜⬜⬛⬛⬜⬛⬛🟥🟦🟦⬛🟨⬛🟦🟦🟦⬛🟥🟥🟥⬛⬛🟨🟨🟨🟨⬛⬜
⬜⬜⬜⬜⬜⬜⬛🟥🟥🟥⬛⬛🟨🟨⬛🟦🟦🟥⬛⬛⬛⬛⬜⬛🟨🟨⬛⬜⬜
⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛🟥⬛🟨🟨🟨⬛🟦⬛🟥🟥🟥⬛⬜⬜⬛⬛⬜⬜⬜
⬜⬜⬜⬜⬜⬜⬛🟥🟥🟥🟥⬛🟨🟨🟨⬛⬛🟥🟥🟥🟥⬛⬜⬜⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬜⬜⬛⬛⬛🟥⬛⬜⬛⬛⬛⬜⬛🟥🟥🟥🟥⬛⬜⬜⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬜⬛🟥🟥🟥⬛⬛⬜⬜⬜⬜⬜⬛🟥🟥⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬛🟥🟥🟥🟥🟥⬛⬜⬜⬜⬜⬜⬜⬛⬛🟥🟥🟥⬛⬜⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬛🟥🟥🟥🟥⬛⬜⬜⬜⬜⬜⬜
⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜
*/