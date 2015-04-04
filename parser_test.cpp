#include "parser.h"


TEST( parser , empty )
{
	parser::cut("");
	puts("=1========");
	parser::cut("{}");
	puts("=2========");
	parser::cut("{[]}");
	puts("=3========");
	parser::cut("{[][][]}{[][][]}");
	puts("=4========");
}

TEST( parser , bracketCut )
{
	parser::cut("{{}");
	parser::cut("{{}}");
	parser::cut("{}}");
	parser::cut("{");
	parser::cut("}");
}

TEST( parser , common )
{
	parser::cut("{[][]}");
	parser::cut("{[<>]}");
	parser::cut("{()[<><>]}");
}
