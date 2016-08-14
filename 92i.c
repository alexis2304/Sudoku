/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   92i.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agougaut <agougaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 11:41:16 by agougaut          #+#    #+#             */
/*   Updated: 2016/08/14 15:06:50 by agougaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Pour les boolean
#define false (1==0)
#define true  (1==1)

// Toutes les fonctions au'on a besoin
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_putchar(char c);
int		ft_atoi_char(char str);

void affichageMod (int grille[9][9])
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i < 9) {
        j = 0;
        while (j < 9) {
            ft_putchar(grille[i][j] + '0');
            ft_putchar(' ');
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}
int absentSurLigne (int k, int grille[9][9], int i)
{
    int j;
    
    j = 0;
    while(j < 9)
    {
        if (grille[i][j] == k)
            return false;
        j++;
    }
        return true;
}

int absentSurColonne (int k, int grille[9][9], int j)
{
    int i;
    
    i = 0;
    while(i < 9)
    {
        if (grille[i][j] == k)
            return false;
        i++;
    }
    return true;
}

int absentSurBloc (int k, int grille[9][9], int i, int j)
{
    int _i = i - (i % 3);
    int _j = j - (j % 3);
    
    i = _i;
    j = _j;
    
    while (i < _i + 3)
    {
        while (j < _j + 3)
        {
            if (grille[i][j] == k)
                return false;
            j++;
        }
        i++;
    }
    return true;
}

int estValide (int grille[9][9], int position)
{
    if (position == 9 * 9)
        return true;

    int i = position / 9;
    int j = position % 9;
    int k = 1;
    
    if (grille[i][j] != 0)
        return estValide(grille, position + 1);
    
    while (k <= 9) {
        if (absentSurLigne(k,grille,i) && absentSurColonne(k,grille,j) && absentSurBloc(k,grille,i,j))
        {
            grille[i][j] = k;
            
            if ( estValide (grille, position+1) )
                return true;
        }
        k++;
    }
    grille[i][j] = 0;

    return false;
}

int main (int argc, char **argv)
{
    int grille[9][9];
    
    int i;
    int j;
    
    i = 1;
    while(argv[i])
    {
        j = 0;
        while (argv[i][j]) {
            grille[i - 1][j] = ft_atoi_char(argv[i][j]);
            j++;
        }
        i++;
    }

    ft_putstr("\nGrille avant\n");
    affichageMod(grille);

    estValide(grille,0);

    ft_putstr("\nGrille apres\n");
    affichageMod(grille);
}
