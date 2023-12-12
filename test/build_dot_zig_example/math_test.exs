defmodule BuildDotZigExample.MathTest do
  use ExUnit.Case

  alias BuildDotZigExample.Math

  describe "sum/2" do
    test "sums integers" do
      assert Math.sum(1, 2) === 3
    end

    test "sums floats" do
      assert Math.sum(4.0, 5.0) === 9.0
    end

    test "sums integers and floats" do
      assert Math.sum(2, 5.0) === 7.0
      assert Math.sum(2.0, 5) === 7.0
    end

    test "raises on invalid arguments" do
      assert_raise ArgumentError, fn -> Math.sum("foo", 3) end
    end
  end

  describe "multiply/2" do
    test "multiplies integers" do
      assert Math.multiply(1, 2) === 2
    end

    test "multiplies floats" do
      assert Math.multiply(4.0, 5.0) === 20.0
    end

    test "multiplies integers and floats" do
      assert Math.multiply(2, 5.0) === 10.0
      assert Math.multiply(2.0, 5) === 10.0
    end

    test "raises on invalid arguments" do
      assert_raise ArgumentError, fn -> Math.multiply("foo", 3) end
    end
  end
end
