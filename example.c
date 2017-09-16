#include <stdio.h>

#include "result.c"

make_result_type(result, char, int)

void print(result r) {
	switch (r.tag) {
		case result_OK:
			printf("ok: '%c'\n", r.val.ok);
			break;
		case result_ERR:
			printf("err: %d\n", r.val.err);
			break;
	}
}

result ok_to_err(char ok_val) {
	return result_err((int)ok_val);
}

result err_to_ok(int err_val) {
	return result_ok((char)err_val);
}

int main() {
	result r_1 = result_map_ok(result_ok('/'), ok_to_err);
	result r_2 = result_map_err(result_err(47), err_to_ok);
	print(r_1);
	print(r_2);
	return 0;
}

