struct matrix3x3
{
  float m[3][3];
};

void MatrixMultiply(matrix3x3& matResult, matrix3x3& matA, matrix3x3& matB)
	{
		for (int c = 0; c < 3; c++)
		{
			for (int r = 0; r < 3; r++)
			{
				matResult.m[c][r] = matA.m[0][r] * matB.m[c][0] +
									matA.m[1][r] * matB.m[c][1] +
									matA.m[2][r] * matB.m[c][2];
			}
		}
	}
