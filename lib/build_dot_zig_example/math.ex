defmodule BuildDotZigExample.Math do
  @on_load :load_nif
  @nif_path "priv/#{Mix.target()}/lib/math"

  defp load_nif do
    Application.app_dir(:build_dot_zig_example, @nif_path)
    |> String.to_charlist()
    |> :erlang.load_nif(0)
  end

  def sum(_, _) do
    :erlang.nif_error(:nif_not_loaded)
  end

  def multiply(_, _) do
    :erlang.nif_error(:nif_not_loaded)
  end
end
