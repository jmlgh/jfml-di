//
// Created by jml on 1/6/25.
//

#include <gtest/gtest.h>
#include "../src/di.h"

TEST(DependencyContainerTest, RegisterAndResolve) {
    DependencyContainer container;

    // Register and resolve a std::string
    container.registerType<std::string>();
    auto resolveString = container.resolve<std::string>();
    *resolveString = "Hello, Dependency Injection!";

    EXPECT_EQ(*resolveString, "Hello, Dependency Injection!");
}

TEST(DependencyContainerTest, UnregisteredTypeThrowsException) {
    DependencyContainer container;

    // Try to resolve a type that has not been registered
    EXPECT_THROW(container.resolve<int>(), std::runtime_error);
}
