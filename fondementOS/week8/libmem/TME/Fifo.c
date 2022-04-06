#include "Fifo.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int initFifo(Swapper *);
unsigned int fifoChoose(Swapper *);
void fifoReference(Swapper *, unsigned int frame);
void finalizeFifo(Swapper *);

int initFifoSwapper(Swapper *swap, unsigned int frames)
{
	return initSwapper(swap, frames, initFifo, NULL, fifoChoose, finalizeFifo);
}

int initFifo(Swapper *swap)
{
	/* A ecrire en TME */
	
	/* Allouer un tableau avec un compteur d'utilisation pour chaque case */
	swap->private_data = calloc(swap->frame_nb, sizeof(int));
	int *load_order = (int *)swap->private_data;
	int i;
	/* Initialisation du tableau */
	for (i = 0; i < swap->frame_nb; i++)
		load_order[i] = 1 + i;
	return 0;
}

unsigned int fifoChoose(Swapper *swap)
{
	/* A ecrire en TME */
	int i, frame=0;
	int * load_order = swap->private_data;
	for ( i = 0; i < swap->frame_nb; i++)
	{
		if (swap->frame[i] == -1)
		{
			frame = i;
			break;
		}
		if( load_order[i] < load_order[frame] )
			frame = i;		
	}

	for ( i = 0; i < swap->frame_nb; i++)
	{
		load_order[i]--;
	}
	
	return frame;
}

void finalizeFifo(Swapper *swap)
{
	free(swap->private_data);
}
