#include <stdio.h>

#include "result.c"

make_result_type(result, char, int)

int check_err(result* r) {
	switch (r->tag) {
		case result_OK:
			return 0;
		case result_ERR:
			return r->val.err;
	}
}

int main() {
	result r_1 = result_ok('a');
	result r_2 = result_err(-1);
	printf("%d, %d\n", check_err(&r_1), check_err(&r_2));
	return 0;
}

