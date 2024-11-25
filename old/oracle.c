/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   oracle.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/19 14:47:55 by mde-beer       #+#    #+#                */
/*   Updated: 2024/11/19 19:13:18 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

void	*ft_ternary(t_bool condition, void *yes, void *no)
{
	if (condition)
		return (yes);
	return (no);
}

t_o_ret	oracle(int ot, int rt, int op, int rp)
{
	const int	swish = ot + abs(rp);
	const int	swash = abs(rt) + op;
	const int	ocost = (int)ft_ternary(ot < op, ot, op) + abs(ot - op);
	const int	rcost = (int)ft_ternary(rt > rp, rt, rp) - abs(rt - rp);
	t_o_ret		ret;

	ret = (t_o_ret){.cost = swish, .top = ot, .place = rp};
	if (ret.cost > swash)
		ret = (t_o_ret){.cost = swash, .top = rt, .place = op};
	if (ret.cost > ocost)
		ret = (t_o_ret){.cost = ocost, .top = ot, .place = op};
	if (ret.cost > rcost)
		ret = (t_o_ret){.cost = rcost, .top = rt, .place = rp};
	return (ret);
}
