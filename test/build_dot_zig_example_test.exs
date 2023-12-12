defmodule BuildDotZigExampleTest do
  use ExUnit.Case
  doctest BuildDotZigExample

  test "greets the world" do
    assert BuildDotZigExample.hello() == :world
  end
end
