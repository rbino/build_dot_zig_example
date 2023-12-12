#include <memory.h>
#include <erl_nif.h>

static ErlNifSInt64 sum_int(ErlNifSInt64 a, ErlNifSInt64 b) { return a + b; }

static double sum_double(double a, double b) { return a + b; }

static ErlNifSInt64 multiply_int(ErlNifSInt64 a, ErlNifSInt64 b) { return a * b; }

static double multiply_double(double a, double b) { return a * b; }

static ERL_NIF_TERM sum(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[]) {
  ERL_NIF_TERM a_term = argv[0];
  ERL_NIF_TERM b_term = argv[1];

  ErlNifTermType type_of_a = enif_term_type(env, a_term);
  ErlNifTermType type_of_b = enif_term_type(env, b_term);

  if (type_of_a == ERL_NIF_TERM_TYPE_INTEGER &&
      type_of_b == ERL_NIF_TERM_TYPE_INTEGER) {
      ErlNifSInt64 a;
      enif_get_int64(env, a_term, &a);
      ErlNifSInt64 b;
      enif_get_int64(env, b_term, &b);
      return enif_make_int64(env, sum_int(a, b));
  } else if (type_of_a == ERL_NIF_TERM_TYPE_INTEGER &&
             type_of_b == ERL_NIF_TERM_TYPE_FLOAT) {
      ErlNifSInt64 a;
      enif_get_int64(env, a_term, &a);
      double b;
      enif_get_double(env, b_term, &b);
      return enif_make_double(env, sum_double(a, b));
  } else if (type_of_a == ERL_NIF_TERM_TYPE_FLOAT &&
             type_of_b == ERL_NIF_TERM_TYPE_INTEGER) {
      double a;
      enif_get_double(env, a_term, &a);
      ErlNifSInt64 b;
      enif_get_int64(env, b_term, &b);
      return enif_make_double(env, sum_double(a, b));
  } else if (type_of_a == ERL_NIF_TERM_TYPE_FLOAT &&
             type_of_b == ERL_NIF_TERM_TYPE_FLOAT) {
      double a;
      enif_get_double(env, a_term, &a);
      double b;
      enif_get_double(env, b_term, &b);
      return enif_make_double(env, sum_double(a, b));
  }

  return enif_make_badarg(env);
}

static ERL_NIF_TERM multiply(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  ERL_NIF_TERM a_term = argv[0];
  ERL_NIF_TERM b_term = argv[1];

  ErlNifTermType type_of_a = enif_term_type(env, a_term);
  ErlNifTermType type_of_b = enif_term_type(env, b_term);

  if (type_of_a == ERL_NIF_TERM_TYPE_INTEGER &&
      type_of_b == ERL_NIF_TERM_TYPE_INTEGER) {
      ErlNifSInt64 a;
      enif_get_int64(env, a_term, &a);
      ErlNifSInt64 b;
      enif_get_int64(env, b_term, &b);
      return enif_make_int64(env, multiply_int(a, b));
  } else if (type_of_a == ERL_NIF_TERM_TYPE_INTEGER &&
             type_of_b == ERL_NIF_TERM_TYPE_FLOAT) {
      ErlNifSInt64 a;
      enif_get_int64(env, a_term, &a);
      double b;
      enif_get_double(env, b_term, &b);
      return enif_make_double(env, multiply_double(a, b));
  } else if (type_of_a == ERL_NIF_TERM_TYPE_FLOAT &&
             type_of_b == ERL_NIF_TERM_TYPE_INTEGER) {
      double a;
      enif_get_double(env, a_term, &a);
      ErlNifSInt64 b;
      enif_get_int64(env, b_term, &b);
      return enif_make_double(env, multiply_double(a, b));
  } else if (type_of_a == ERL_NIF_TERM_TYPE_FLOAT &&
             type_of_b == ERL_NIF_TERM_TYPE_FLOAT) {
      double a;
      enif_get_double(env, a_term, &a);
      double b;
      enif_get_double(env, b_term, &b);
      return enif_make_double(env, multiply_double(a, b));
  }

  return enif_make_badarg(env);
}

static ErlNifFunc nif_funcs[] = {
        {"sum", 2, sum},
        {"multiply", 2, multiply},
};

ERL_NIF_INIT(Elixir.BuildDotZigExample.Math, nif_funcs, NULL, NULL, NULL, NULL)
