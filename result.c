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
}					\
\
struct name name##_map(name self, name (*f_ok)(ok_type), name (*f_err)(err_type)) {	\
	switch (self.tag) {								\
		case name##_OK:								\
			return (*f_ok)(self.val.ok);					\
		case name##_ERR:							\
			return (*f_err)(self.val.err);					\
	}										\
}											\
\
struct name name##_map_ok(name self, name (*f)(ok_type)) {	\
	switch (self.tag) {					\
		case name##_OK:					\
			return (*f)(self.val.ok);		\
		case name##_ERR:				\
			return self;				\
	}							\
}								\
\
struct name name##_map_err(name self, name (*f)(err_type)) {	\
	switch (self.tag) {					\
		case name##_OK:					\
			return self;				\
		case name##_ERR:				\
			return (*f)(self.val.err);		\
	}							\
}
