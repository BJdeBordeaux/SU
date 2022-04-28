#include "fat.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int file_found(char *file)
{
  int i;
  struct ent_dir *pt = pt_DIR;

  for (i = 0; i < NB_DIR; i++)
  {
    if ((pt->del_flag) && (!strcmp(pt->name, file)))
      return 0;
    pt++;
  }
  /* finchier n'existe pas */
  return 1;
}

void list_fat()
{
  int i;
  short *pt = pt_FAT;
  for (i = 0; i < NB_ENT_FAT; i++)
  {
    if (*pt)
      printf("%d ", i);
    pt++;
  }
  printf("\n");
}

void list_dir()
{
  /* A COMPLETER */
  int i;
  struct ent_dir *pt = pt_DIR;
  short *pt_fat = pt_FAT;
  int total = 0;
  for (i = 0; i < NB_DIR; i++)
  {
    if (pt->del_flag == 1)
    {
      printf("%d %s\n", pt->size, pt->name);
      printf("%d", pt->first_bloc);
      short *j = pt_fat + pt->first_bloc;
      while (*j != -1)
      {
        printf(", %d", *j);
        j = pt_fat + *j;
      }
      printf("\n");
      total += pt->size;
    }
    pt++;
  }
  printf("Total: %d\n", total);
}

int cat_file(char *file)
{
  /* A COMPLETER */
  int i;
  struct ent_dir *pt = pt_DIR;
  short *pt_fat = pt_FAT;
  for (i = 0; i < NB_DIR; i++)
  {
    if (strcmp(pt->name, file) == 0)
    {
      char* buffer = malloc(pt->size);
      short *j = pt_fat + pt->first_bloc;
      while (*j != -1)
      {
        read_sector(*j, buffer);
        printf("%s", buffer);
        j = pt_fat + *j;
      }
      return 0;
    }
    pt++;
  }
  return -1;
}

int mv_file(char *file1, char *file2)
{
  /* A COMPLETER */
  struct ent_dir *pt = pt_DIR;
  int i;
  for (i = 0; i < NB_DIR; i++)
  {
    if (strcmp(pt->name, file1) == 0)
    {
      strcpy(pt->name, file2);
      return write_DIR_FAT_sectors();
    }
    pt++;
  }
  return -1;
}

int delete_file(char *file)
{
  /* A COMPLETER */
  struct ent_dir *pt = pt_DIR;
  short *pt_fat = pt_FAT;
  int i;
  for (i = 0; i < NB_DIR; i++)
  {
    if (strcmp(pt->name, file) == 0)
    {
      short *j = pt_fat + pt->first_bloc;
      while (*j != -1)
      {
        short tmp = *j;
        *j = 0;
        j = pt_fat + tmp;
      }
      pt->del_flag = 0;
      return write_DIR_FAT_sectors();
    }
    pt++;
  }
  return -1;
}

int create_file(char *file)
{
  /* A COMPLETER */
  struct ent_dir *pt = pt_DIR;
  int i;
  short *pt_fat = pt_FAT;
  for (i = 0; i < NB_DIR; i++)
  {
    if (strcmp(pt->name, file) == 0)
    {
      return -1;
    }
    pt++;
  }
  pt = pt_DIR;
  for (i = 0; i < NB_DIR; i++)
  {
    if (pt->del_flag == 0)
    {
      strcpy(pt->name, file);
      pt->del_flag = 1;
      pt->size = 0;
      pt->first_bloc = FIN_FICHIER;
      pt->last_bloc = FIN_FICHIER;
      return write_DIR_FAT_sectors();
    }
    pt++;
  }
  return -1;
}

short alloc_bloc()
{
  /* A COMPLETER */
  short *pt_fat = pt_FAT;
  int i;
  for (i = 0; i < NB_ENT_FAT; i++)
  {
    if (*pt_fat == 0)
    {
      *pt_fat = FIN_FICHIER;
      return i;
    }
    pt_fat++;
  }
  return -1;
}

int append_file(char *file, char *buffer, short size)
{
  /* A COMPLETER */
  struct ent_dir *pt = pt_DIR;
  short *pt_fat = pt_FAT;
  int i;
  for (i = 0; i < NB_DIR; i++)
  {
    if (strcmp(pt->name, file) == 0)
    {
      int nb_bloc = (size + SIZE_SECTOR - 1) / SIZE_SECTOR;
      for (int j = 0; j < nb_bloc; j++)
      {
        short bloc = alloc_bloc();
        if (bloc == -1)
        {
          return -1;
        }
        short tmp = pt->last_bloc;
        pt->last_bloc = bloc;
        pt->size += SIZE_SECTOR;
        write_sector(bloc, buffer + j * SIZE_SECTOR);
        short *p = pt_fat + bloc;
        *p = FIN_FICHIER;
        p = pt_fat + tmp;
        *p = bloc;
        if (write_DIR_FAT_sectors() == -1)
        {
          return -1;
        }
      }
      return 0;
    }
    pt++;
  }
  return -1;
}

struct ent_dir *read_dir(struct ent_dir *pt_ent)
{
  /* A COMPLETER */
}
