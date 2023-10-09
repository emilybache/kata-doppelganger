using Doppelganger;
using Moq;

namespace Doppelganger.Tests
{
    public class CalculatorTests
    {
        [Test]
        public void DoNotThrowWhenAuthorized()
        {
            var authorizer = new StubAuthorizer(true);
            var calculator = new Calculator(authorizer);
            Assert.AreEqual(3, calculator.Add(1,2));
        }        
        
        [Test]
        public void ThrowWhenNotAuthorized()
        {
            var authorizer = new StubAuthorizer(false);
            var calculator = new Calculator(authorizer);
            Assert.Throws<Exception>(() => calculator.Add(1, 2));
        }
        
        [Test]
        public void DoNotThrowWhenAuthorized_Moq()
        {
            var authorizer = new Mock<IAuthorizer>();
            authorizer.Setup(a => a.Authorize()).Returns(true);
            var calculator = new Calculator(authorizer.Object);
            Assert.AreEqual(3, calculator.Add(1,2));
        }
        
        [Test]
        public void ThrowWhenNotAuthorized_Moq()
        {
            var authorizer = new Mock<IAuthorizer>();
            authorizer.Setup(a => a.Authorize()).Returns(false);
            var calculator = new Calculator(authorizer.Object);
            Assert.Throws<Exception>(() => calculator.Add(1, 2));
        }
    }

    public class StubAuthorizer : IAuthorizer
    {
        private bool _authorize;

        public StubAuthorizer(bool authorize)
        {
            _authorize = authorize;
        }

        public bool Authorize()
        {
            return _authorize;
        }
    }
}
