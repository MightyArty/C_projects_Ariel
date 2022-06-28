#include <stdio.h>
#include "graph.h"
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"



// building new graph from scratch
void
build_graph_cmd (pnode * head, char *input)
{


  int size = 0;
  scanf ("%d", &size);
  if (size > 0)
    {
      for (int i = 1; i < size; ++i)
	{
	  put_in_the_end (i, head);
	}
    }
  while (scanf ("%c", input))
    {
    	// if input is 'n'
      if (*input == 110)
	{
	  int src;
	  int dest, w;
	  scanf ("%d", &src);
	  pnode first = idFinder (head, src);
	  while (scanf ("%d", &dest))
	    {
				
				// if input is between A-Z and not 'n'
	      if ((*input >= 65 && *input <= 90) || *input != 110)
		break;
	      scanf ("%d", &w);
	      pnode second = idFinder (head, dest);

	      
	      if (!update (first, second, w))
		{
		  createEdge (first, second, w);
		}
	    }
	}
      else if (*input >= 65 && *input <= 90)
	{
	  break;
	}
    }
}

void
insert_node_cmd (pnode * head, char *choose)
{
	
	// if choose = 'B'
  if (*choose == 66)
    {
      int src;
      scanf ("%d", &src);
      pnode insertion_node = idFinder (head, src);

      if (insertion_node == NULL)
	{
	  insertion_node = newNode (src);

	  insertion_node->w = 0;
	  insertion_node->tag = 0;
	  insertion_node->previous = -1;
	  insertion_node->edges = NULL;
	  insertion_node->next = NULL;
	  int dest, w;
	  while (scanf ("%d", &dest))
	    {
	    	// if input is between A-Z
	      if (dest >= 65 && dest <= 90)
		{
		  break;
		}
	      pnode second = idFinder (head, dest);
	      scanf ("%d", &w);
	      if (!update (insertion_node, second, w))
		{
		  createEdge (insertion_node, second, w);
		}
	    }
	  pnode runNode = *head;
	  while (runNode->next != NULL)
	    {
	      runNode = runNode->next;
	    }
	  runNode->next = insertion_node;
	}
      else
	{
	  remove_edges_out (head, insertion_node);

	  int dest, w;
	  while (scanf ("%d", &dest))
	    {
	    	// if input is between A-Z and not 'n'
	      if (dest >= 65 && dest <= 90)
		{
		  break;
		}
	      pnode second = idFinder (head, dest);
	      scanf ("%d", &w);
	      if (!update (insertion_node, second, w))
		{
		  createEdge (insertion_node, second, w);
		}
	    }
	}
    }
}

void
delete_node_cmd (pnode * head, char *choose)
{
	
	// if choose = 'D'
  if (*choose == 68)
    {
      int node_id;
      scanf ("%d", &node_id);

      pnode node_to_delete = idFinder (head, node_id);
      if (node_to_delete == NULL)
	return;
      remove_edges_out (head, node_to_delete);
      remove_edges_in (head, node_to_delete);

      pnode *temp = head;
      pnode temp2 = *head;

      if (temp != NULL)
	{
	  if (temp2->node_num == node_id)
	    {
	      *temp = temp2->next;
	      temp2->next = NULL;
	      free (temp2);
	      return;
	    }
	}

    }


}


void
deleteGraph_cmd (pnode * head, char *input)
{
  pnode node_to_delete = *head;
  while (node_to_delete->next != NULL)
    {
      pnode run = node_to_delete->next;

      remove_edges_out (head, node_to_delete);
      pnode *temp = head;
      pnode temp2 = *head;
      *temp = temp2->next;
      temp2->next = NULL;
      free (temp2);
      node_to_delete = run;
    }
  remove_edges_out (head, node_to_delete);
  free (node_to_delete);
}

void
shortsPath_cmd (pnode * head)
{


  int src, dest;
  scanf ("%d", &src);
  scanf ("%d", &dest);

  pnode first = idFinder (head, src);
  pnode second = idFinder (head, dest);

  reset (head);
  int distance = dijkstra (first, second, head);

  printf ("Dijsktra shortest path: %d \n", distance);

}

void
TSP_cmd (pnode * head)
{
  int target_city;
  int ans = -1;
  scanf ("%d", &target_city);

  pnode cities_arr[target_city];
  for (int i = 0; i < target_city; ++i)
    {
      int n;
      scanf ("%d", &n);
      cities_arr[i] = idFinder (head, n);
    }
  bool is_in[target_city];
  for (int i = 0; i < target_city; ++i)
    {
      is_in[i] = false;
    }
  for (int i = 0; i < target_city; ++i)
    {
      for (int j = 0; j < target_city; ++j)
	{
	  if (i == j)
	    continue;
	  reset (head);
	  int dist = dijkstra (cities_arr[i], cities_arr[j], head);
	  pnode reversePath = cities_arr[j];
	  int index_runner = 0;
	  for (int k = 0; k < target_city; ++k)
	    {
	      is_in[k] = false;
	    }
	  while (reversePath->previous != -1)
	    {
	      for (int k = 0; k < target_city; ++k)
		{
		  if (reversePath->node_num == cities_arr[k]->node_num)
		    is_in[index_runner++] = true;
		}
	      reversePath = idFinder (head, reversePath->previous);
	    }
	  for (int k = 0; k < target_city; ++k)
	    {
	      if (reversePath->node_num == cities_arr[k]->node_num)
		is_in[index_runner++] = true;
	    }
	  bool allIn = true;
	  for (int k = 0; k < target_city; ++k)
	    {
	      if (is_in[k] == false)
		allIn = false;
	    }
	  if (allIn)
	    {
	      if (dist < ans || ans == -1)
		{
		  ans = dist;
		  break;
		}
	    }
	}
    }


  printf ("TSP shortest path: %d \n", ans);
}


pnode
newNode (int node_num)
{
  pnode insertion_node = malloc (sizeof (node));
  if (insertion_node == NULL)
    return NULL;
  insertion_node->node_num = node_num;
  insertion_node->tag = 0;
  insertion_node->w = 0;
  insertion_node->previous = -1;
  insertion_node->edges = NULL;
  insertion_node->next = NULL;
  return insertion_node;
}

void
put_in_the_end (int value, pnode * head)
{
  pnode node_runner = *head;
  if (node_runner == NULL)
    {
      node_runner = newNode (value);
      return;
    }
  while (node_runner->next != NULL)
    {
      node_runner = node_runner->next;
    }
  pnode previous = node_runner;
  node_runner = newNode (value);
  previous->next = node_runner;
}

pnode
idFinder (pnode * head, int node_id)
{
  pnode curr = *head;
  while (curr != NULL)
    {
      if (curr->node_num == node_id)
	return curr;
      curr = curr->next;
    }
  return curr;
}

bool
update (pnode src, pnode dest, int w)
{
  pedge runEdge = src->edges;
  if (runEdge == NULL)
    return false;
  while (runEdge != NULL)
    {
      if (runEdge->endpoint == dest)
	{
	  runEdge->w = w;
	  return true;
	}
      runEdge = runEdge->next;
    }
  return false;
}

void
createEdge (pnode src, pnode dest, int w)
{
  pedge ed = malloc (sizeof (edge));
  pedge runEdge = src->edges;
  if (runEdge == NULL)
    {
      ed->w = w;
      ed->endpoint = dest;
      ed->next = NULL;
      src->edges = ed;
    }
  else
    {
      while (runEdge->next != NULL)
	{
	  runEdge = src->edges->next;
	}
      ed->w = w;
      ed->endpoint = dest;
      ed->next = NULL;
      runEdge->next = ed;
    }
}

void
remove_edges_in (pnode * head, pnode node)
{
  pnode temp_node = *head;
  while (temp_node != NULL)
    {
      if (temp_node == node)
	temp_node = temp_node->next;
      pedge previous, curr = temp_node->edges;
      if (curr != NULL)
	{
	  if (curr->endpoint == node)
	    {
	      temp_node->edges = curr->next;
	      free (curr);
	      temp_node = temp_node->next;
	      continue;
	    }
	}
      while (curr != NULL)
	{
	  previous = curr;
	  curr = curr->next;


	  if (curr->endpoint == node || curr->endpoint == NULL)
	    {
	      if (curr->next != NULL)
		{
		  previous->next = curr->next->next;
		  free (curr);
		  break;
		}
	      else
		{
		  previous->next = NULL;
		  free (curr);
		  break;
		}
	    }

	  curr = curr->next;
	}
      temp_node = temp_node->next;
    }
}

void
remove_edges_out (pnode * head, pnode node)
{
  pnode temp_node = *head;

  while (temp_node != node)
    {
      temp_node = temp_node->next;
    }
  if (temp_node->edges == NULL)
    return;
  pedge previous, curr = temp_node->edges;
  if (curr->next != NULL)
    {
      while (curr->next != NULL)
	{
	  previous = curr;
	  curr = curr->next;
	  free (previous);
	}
    }
  free (curr);
  temp_node->edges = NULL;
}

int
dijkstra (pnode src, pnode dest, pnode * src_pointer)
{
  pnode head = tempNode (src->node_num, 0);
  pnode *phead = &head;
  head->tag = 1;
  pnode curr = src;
  curr->w = 0;
  curr->tag = 1;

  while ((*phead) != NULL)
    {
      curr = idFinder (src_pointer, head->node_num);
      curr->tag = 1;
      node *temp = *phead;
      (*phead) = (*phead)->next;
      free(temp);


      pedge edge_runner = curr->edges;
      while (edge_runner != NULL)
	{
	  pnode target_node = edge_runner->endpoint;
	  if (target_node == src)
	    {
	      edge_runner = edge_runner->next;
	      continue;
	    }

	  int pathWeight = curr->w + edge_runner->w;
	  if (target_node->w >= pathWeight || target_node->w == 0)
	    {
	      target_node->w = pathWeight;
	      if (idFinder (phead, target_node->node_num) != NULL)
		{
		  idFinder (phead, target_node->node_num)->w = pathWeight;
		  target_node->previous = curr->node_num;
		  edge_runner = edge_runner->next;
		  continue;
		}
	      target_node->previous = curr->node_num;
	    }
	  if (target_node->tag == 0)
	    {
	      insert (phead, target_node->node_num, target_node->w);
	    }
	  edge_runner = edge_runner->next;
	}

    }
  free (head);
  return idFinder (src_pointer, dest->node_num)->w;
}

void
reset (pnode * head)
{
  pnode run = *head;
  while (run != NULL)
    {
      run->w = 0;
      run->tag = 0;
      run->previous = -1;
      run = run->next;
    }
}


// creating a new node
node *
tempNode (int id, int w)
{
  node *temp = (node *) malloc (sizeof (node));
  temp->node_num = id;
  temp->w = w;
  temp->next = NULL;
  temp->tag = 0;

  return temp;
}

void
insert (node ** head, int id, int w)
{
  node *start = (*head);

  node *temp = tempNode (id, w);

  if (*head != NULL)
    {
      if ((*head)->w > w)
	{

	  temp->next = *head;
	  (*head) = temp;
	}
      else
	{

	  while (start->next != NULL && start->next->w < w)
	    {
	      start = start->next;
	    }

	  temp->next = start->next;
	  start->next = temp;
	}
    }
  else
    {
      *head = temp;
    }
}
