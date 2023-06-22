package esercizio_4;

import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

/**
 * This class serves to run the tests
 * 
 * @author Alessandro, Sofia, Valerio
 */

public class PriorityQueueTestsRunner {
    /**
     * @param args the command lines arguments
     */

    public static void main(String[] args) {
        Result result = JUnitCore.runClasses(PriorityQueueTests.class);
        for (Failure failure : result.getFailures()) {
            System.out.println(failure.toString());
        }
        System.out.println(result.wasSuccessful());
    }
}