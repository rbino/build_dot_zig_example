defmodule BuildDotZigExample.MixProject do
  use Mix.Project

  def project do
    [
      app: :build_dot_zig_example,
      version: "0.1.0",
      elixir: "~> 1.15",
      compilers: [:build_dot_zig] ++ Mix.compilers(),
      start_permanent: Mix.env() == :prod,
      deps: deps()
    ]
  end

  # Run "mix help compile.app" to learn about applications.
  def application do
    [
      extra_applications: [:logger]
    ]
  end

  # Run "mix help deps" to learn about dependencies.
  defp deps do
    [
      {:build_dot_zig, "~> 0.6.0"}
    ]
  end
end
