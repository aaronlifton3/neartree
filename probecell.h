class probecell
{
	int cellD[3];

public:
	probecell()
	{
		
	}
	
	probecell(int val0, int val1, int val2)
	{
		cellD[0] = val0;
		cellD[1] = val1;
		cellD[2] = val2;
	}

	int getData(int index)
	{
		return cellD[index];
	}

	probecell operator- (const probecell &probecell2) const
	{
		probecell cellReturn
			(cellD[0] - probecell2.cellD[0],
			cellD[1] - probecell2.cellD[1],
			cellD[2] - probecell2.cellD[2]);
		return(cellReturn);
	}

	int Norm(void) const
	{
		return(abs(cellD[0]) + abs(cellD[1]) + abs(cellD[2]));
	}
};