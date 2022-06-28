#include <stdio.h>
#include "graph.h"
#include <stdlib.h>
#include <stdbool.h>
#include "string.h"
#include "functions.h"


int
main ()
{

  pnode current = newNode (0);
  current->w = 0;
  current->tag = 0;
  current->previous = -1;
  current->edges = NULL;
  current->next = NULL;
  pnode *return_node = &current;


  bool flag = true;
  char *choose = (char *) malloc (1);
  *choose = 'w';
  char _case = 'w';
  // EOF - stands for end of the file
  while (*choose != EOF)
    {
      scanf ("%c", &_case);
      *choose = _case;
      if (*choose == '\n')
	break;
			// if input = 'A'
      if (*choose == 65)
	{

	  if (!flag)
	    {
	      if (current != NULL)
		{
		  deleteGraph_cmd (return_node, choose);
		}
	      current = newNode (0);
	      current->w = 0;
	      current->tag = 0;
	      current->edges = NULL;
	      current->next = NULL;
	      *return_node = current;
	      flag = true;
	    }
	  flag = false;
	  
	  build_graph_cmd (return_node, choose);
	}
			// if first = 'B'
      if (*choose == 66)
	{
	  insert_node_cmd (return_node, choose);
	}
			// if first = 'D'
      if (*choose == 68)
	{
	  delete_node_cmd (return_node, choose);
	}
			// if first = 'S'
      if (*choose == 83)
	{
	  shortsPath_cmd (return_node);
	}
			// if first = 'T'
      if (*choose == 84)
	{
	  TSP_cmd (return_node);
	}

    }
  deleteGraph_cmd (return_node, choose);
  free (choose);
  return 0;
}
