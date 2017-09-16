#define make_result_type(name, ok_type, err_type) \
typedef struct name {		\
	union name##_val {	\
		ok_type ok;	\
		err_type err;	\
	} val;			\
	enum name##_tag {	\
		name##_OK,	\
		name##_ERR,	\
	} tag;			\
} name;				\
\
struct name name##_ok(ok_type val) {	\
	name r;				\
	r.val.ok = val;			\
	r.tag = name##_OK;		\
	return r;			\
}					\
\
struct name name##_err(err_type val) {	\
	name r;				\
	r.val.err = val;		\
	r.tag = name##_ERR;		\
	return r;			\
}
