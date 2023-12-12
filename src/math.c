#include <memory.h>
#include <erl_nif.h>

static ERL_NIF_TERM sum(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // TODO: implement NIF
    return enif_raise_exception(env, enif_make_atom(env, "not_implemented"));
}

static ERL_NIF_TERM multiply(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // TODO: implement NIF
    return enif_raise_exception(env, enif_make_atom(env, "not_implemented"));
}

static ErlNifFunc nif_funcs[] =
{
    {"sum", 2, sum},
    {"multiply", 2, multiply},
};

ERL_NIF_INIT(Elixir.BuildDotZigExample.Math, nif_funcs, NULL, NULL, NULL, NULL)
